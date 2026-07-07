function findMedianSortedArrays(nums1: number[], nums2: number[]): number {
  const merged: number[] = [...nums1, ...nums2].sort((a, b) => a - b);
  const len = merged.length;
  const mid = Math.floor(len / 2);
  return len % 2 === 0 ? (merged[mid - 1] + merged[mid]) / 2 : merged[mid];
}
